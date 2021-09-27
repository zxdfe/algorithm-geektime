var mergeTwoLists = function(l1, l2) {
    // 创建头节点
    const head = new ListNode(0);
    // 创建一个指针, 指向head
    let prev = head;
    while (l1 != null && l2 != null) {
        if (l1.val < l2.val) {
            prev.next = l1;
            l1 = l1.next;
        } else {
            prev.next = l2;
            l2 = l2.next;
        }
        // 每次比较后指针prev也要移动一位
        prev = prev.next;
    }

    // if (l1 !== null) prev.next = l1;
    // if (l2 !== null) prev.next = l2;
    prev.next = l1 === null ? l2 : l1;

    return head.next;
};